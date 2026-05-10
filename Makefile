SHELL := /bin/sh
TARGET := prog

CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic
BUILD := build

CFG ?= debug

ifeq ($(CFG),debug)
	CXXFLAGS += -g -O1
else
	CXXFLAGS += -O3
endif

OUT := $(BUILD)/$(CFG)/$(TARGET)

OBJDIR := $(BUILD)/$(CFG)/objs
SRCS := $(shell find src/ -name "*.cpp")
OBJS := $(addprefix $(OBJDIR)/, $(SRCS:%.cpp=%.o))
DEPS := $(OBJS:.o=.d)

all: check $(OUT)

check:
ifneq ($(CFG),release)
ifneq ($(CFG),debug)
	@echo "Invalid configuration "$(CFG)" specified."
	@exit 1
endif
endif

$(OUT): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

.PHONY: all check clean

clean:
	-rm -rv $(BUILD)/*

-include $(DEPS)

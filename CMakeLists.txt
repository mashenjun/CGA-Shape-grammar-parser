cmake_minimum_required(VERSION 3.7)
project(CGA_Shape)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp shape/shape.cpp shape/shape.h shape/geometry.cpp shape/geometry.h shape/terminalShape.cpp shape/terminalShape.h shape/nonterminalShape.cpp shape/nonterminalShape.h util/scopeRule.cpp util/scopeRule.h util/basicSplitRule.cpp util/basicSplitRule.h util/repeatRule.cpp util/repeatRule.h util/componentSplitRule.cpp util/componentSplitRule.h parser/y_io_2.h util/generalProcessor.cpp util/generalProcessor.h shape/rule.cpp shape/rule.h)
add_executable(CGA_Shape ${SOURCE_FILES})
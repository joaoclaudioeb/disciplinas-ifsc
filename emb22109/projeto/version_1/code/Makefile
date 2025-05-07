BUILD_DIR=build
CMAKE_SRC_DIR=.

MAKEFLAGS += --no-print-directory

.PHONY:
all: CMakeLists.txt
	@cmake --build $(BUILD_DIR)

.PHONY:
configure: CMakeLists.txt
	@cmake -S $(CMAKE_SRC_DIR) -B $(BUILD_DIR) 

.PHONY:
clean: CMakeLists.txt
	@cmake --build $(BUILD_DIR) --target clean

.PHONY:
cleanall: CMakeLists.txt
	rm -rf $(CMAKE_SRC_DIR)/build

## python project variables

$(info Reading amb/xanrMake/python/projVars.makefile)

# standalone implies --recurse-all --recurse-stdlib
EXE_TYPE :=# --standalone
EXE_TYPE := --recurse-all
#PY_VERSION := --python-version=3.5
CXX_BACKEND := --clang
TRACING_FLAGS :=# --show-progress
BUILD_ARTIFACT_FLAGS := --remove-output

NUITKA_FLAGS := \
   $(EXE_TYPE) \
   $(PY_VERSION) \
   $(CXX_BACKEND) \
   $(TRACING_FLAGS) \
   $(BUILD_ARTIFACT_FLAGS)

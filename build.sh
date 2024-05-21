#!/bin/bash

print_usage() {
    echo ""
    echo "Usage:"
    echo ""
    echo "  $0 [options]"
    echo ""
    echo "Options:"
    echo ""
    echo "  -h, --help        Print this help."
    echo "  -b, --build       Use g++ or cmake to build the project. Avalible option[both, g++, cmake], default both"
    echo "  -c, --clean       Start building after cleaning cache."
    echo ""
}

parse_args() {
    opt_string="hcb:"
    opt_string_long="help,clean,build:"
    GET_OPT_ARGS=$(getopt -o "$opt_string" -l "$opt_string_long" -n "$0" -- "$@")
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        echo ""
        print_usage
        # exit 1
    fi

    eval set -- "${GET_OPT_ARGS}"
    while true; do
        case "$1" in
        -h | --help )
            print_usage
            # exit 0
            ;;
        -b | --build )
            BUILD_WAY="$2"
            shift 2
            ;;
        -c | --clean )
            CLEAN_BUILD=true
            shift
            ;;
        --)
            shift
            break
            ;;
        *)
            echo ""
            echo "Invalid option: $1." >&2
            print_usage
            # exit 1
            ;;
        esac
    done
    if [ -z ${BUILD_WAY} ]; then
        BUILD_WAY="cmake"
    fi
}

root_dir=$(cd "$(dirname "$0")"; pwd)
export INSTALL_DIR="${root_dir}/install"
export BUILD_DIR="${root_dir}/build"

function build_all() {
    echo "Starting build..."
    echo "Build DIR: $BUILD_DIR"
    echo "Install DIR: $INSTALL_DIR"

    mkdir -p ${INSTALL_DIR}
    mkdir -p ${BUILD_DIR}

    echo "Starting build:"
    if [ "$BUILD_WAY" = "both" ] || [ "$BUILD_WAY" = "cmake" ]; then
        echo "Start cmake building..."
        cd ${BUILD_DIR}
        protoc -I=../proto --cpp_out=. ../proto/pro.proto
        cmake ..
        # make PREFIX=${INSTALL_DIR} install
        make -j 8
        cd ${root_dir}
        echo "Finished cmake building"
    fi

    if [ "$BUILD_WAY" = "both" ] || [ "$BUILD_WAY" = "g++" ]; then
        echo "Start g++ building..."
        cd ${root_dir}
        source g++build.sh
        echo "Finish g++ building..."
    fi
    
}

function  build_clean() {
    rm -rf ${INSTALL_DIR}
    rm -rf ${BUILD_DIR}
}

main() {
    parse_args "$@"
    if [ $CLEAN_BUILD = true ]; then
        build_clean
    fi
    build_all
}

main "$@"

# exit 0
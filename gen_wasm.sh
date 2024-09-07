#!/usr/bin/bash
# shell script to prepare for wasm compilation
# to be used in the makefile

NEW_DIR="EKUN_WASM"
SRC="src"

FILES=("dbg.h" "ekbytecode.c" "ekbytecode.h" "ekdarray.h" "ekdisassemble.c" "eklex.c" "eklex.h" "ekmem.c" "ekmem.h" "ekparser.y" "ekparser.h" "eksymbol.c" "eksymbol.h" "ektypes.c" "ektypes.h" "ekvm.h" "ekvm.c" "utils.h")


mkdir -p ${NEW_DIR}

#update the file to use the custom_printf which write to a div in the html file
#
for file in ${FILES[@]};  do
    if [[ ! -f "${SRC}/${file}" ]]; then
        echo "Error: ${file} does not exist in ${SRC}"
        exit 1
    fi
    sed -E 's/\b(printf|fprintf)\b/custom_printf/g'  "${SRC}/${file}" > "${NEW_DIR}/${file}"
done
cp "${SRC}/wasm_files/ekun_wasm.c" "${NEW_DIR}/ekun.c"
cp "${SRC}/wasm_files/ekun_wasm.h" "${NEW_DIR}/ekun.h"

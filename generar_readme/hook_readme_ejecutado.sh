#!/bin/bash

for added_file in $(git diff --cached --name-only --diff-filter=ACM); do
	added_file_dir=$(dirname $added_file);
    if [[ $added_file_dir =~ ^[0-9]+$ ]] && ! grep -q $added_file_dir README.md; then
	    echo "No se encontró referencia al problema $added_file_dir en el README. Por favor ejecuta el script de actualización."
		exit 1
	fi
done

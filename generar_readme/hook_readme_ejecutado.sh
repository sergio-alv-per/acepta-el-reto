#!/bin/sh

for dir in $(find . -maxdepth 1 -type d -regex './[0-9]+'); do
    if ! grep -q $(basename $dir) README.md; then
	    echo "No se encontró referencia al problema $dir en el README. Por favor ejecuta el script de actualización."
		exit 1
	fi
done

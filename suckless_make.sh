#!/bin/bash

src="src"
objects="bin"

out="cdoom"

function compile() {
	mkdir $objects

	files=$(ls src)
	file_index=0

	printf "COMPILING:\n"
	printf "\n"
	for file in $files; do
		file_index=$((file_index+1))
		file_amount=$(ls $src | wc -l)
		printf "\033[33m[Compiling $file]" 
		printf "\033[0m $file_index/$file_amount\n"

		file_name=${file:0:$((${#file}-2))}	
		gcc -c $src/$file -o $objects/$file_name.o -Iinclude/
	done
	printf "\n"
}

function link() {
	printf "LINKING...\n"
	printf "\n"
	gcc $objects/*.o -o $out -lncurses 
	rm -r $objects
	printf "\n"
}

function build() {
	compile
	link
}

function run() {
	if [ -f $out ]; then
		printf "RUNNING...\n"
		printf "\n"
		./$out
	else
		printf "\033[31m COMPILE ERROR\n\033[0m"
	fi
}

for callback in $@; do
	$callback
done

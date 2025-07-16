#!/bin/bash
start_time=$(date +%s)

src_game="src"
src_engine="include/eng"
objects="bin"
lib="lib"

out="cdoom"

function compile_engine() {
	files=$(ls $src_engine | grep "\.c")
	file_index=0

	printf "COMPILING ENGINE:\n"
	printf "\n"
	for file in $files; do
		file_index=$((file_index+1))
		file_amount=$(ls $src_engine | grep "\.c" | wc -l)
		printf "\033[33m[Compiling $file]" 
		printf "\033[0m $file_index/$file_amount\n"

		file_name=${file:0:$((${#file}-2))}	
		gcc -c $src_engine/$file -o $lib/$file_name.o
	done
	printf "\n"
}

function compile_game() {
	mkdir -p $objects

	files=$(ls $src_game)
	file_index=0

	printf "COMPILING GAME:\n"
	printf "\n"
	for file in $files; do
		file_index=$((file_index+1))
		file_amount=$(ls $src_game | grep "\.c" | wc -l)
		printf "\033[33m[Compiling $file]" 
		printf "\033[0m $file_index/$file_amount\n"

		file_name=${file:0:$((${#file}-2))}	
		gcc -c $src_game/$file -o $objects/$file_name.o -Iinclude/
	done
	printf "\n"
}

function link() {
	printf "LINKING...\n"
	printf "\n"
	cp $lib/* $objects/
	gcc $objects/*.o -o $out -lncurses -lm 
	printf "\n"
}

function clean() {
	rm -r $objects
}

function build() {
	compile_engine
	compile_game
	link
	clean
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

end_time=$(date +%s)
elapsed=$((end_time - start_time))

echo "Done in $elapsed seconds"

#!/bin/bash


test_path="./Your"

tests=($(ls $test_path | grep ".s$"))


for file in "${tests[@]}"
do
	./asm $test_path/$file
done


test_path_2="./Original"

tests_2=($(ls $test_path_2 | grep ".s$"))


for file in "${tests_2[@]}"
do
	./asm_or $test_path_2/$file
done

#!/bin/sh

#Edit main_path: students' folder will be created inside
main_path="./"

#########################################################################################
students="./students.txt"
for student in $(cat < $students); do
  echo "Creating: $main_path/$student"
  mkdir "$main_path/$student"
done

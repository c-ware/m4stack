#!/bin/sh
# Run checks

echo Running test tests/init
$1 tests/init
echo Ran test tests/init

echo Running test tests/free
$1 tests/free
echo Ran test tests/free

echo Running test tests/push
$1 tests/push
echo Ran test tests/push

echo Running test tests/pop
$1 tests/pop
echo Ran test tests/pop

echo Running test tests/peek
$1 tests/peek
echo Ran test tests/peek

echo Running test tests/is_empty
$1 tests/is_empty
echo Ran test tests/is_empty

echo Running test tests/length
$1 tests/length
echo Ran test tests/length

echo Running test tests/addremov
$1 tests/addremov
echo Ran test tests/addremov

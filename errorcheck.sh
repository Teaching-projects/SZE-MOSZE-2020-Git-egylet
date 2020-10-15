#!/bin/bash
if grep --quiet "error" "./cppcheck_expected_output.txt"
then exit 1
fi
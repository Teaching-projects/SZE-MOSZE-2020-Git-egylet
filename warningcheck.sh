#!/bin/bash
if grep --quiet "warning" "./cppcheck_expected_output.txt"
then exit 1
fi
#!/bin/sh

USE_FIFO=0
[ "$1" == "-v" ] && USE_FIFO=1 && shift

do_test() {
    if [ ${USE_FIFO} -gt 0 ]
    then
        valgrind --track-origins=yes --leak-check=full --error-exitcode=1 -s "${1}" --success > >(tee result.raw) 2>&1
    else
        valgrind --track-origins=yes --leak-check=full --error-exitcode=1 -s "${1}" --success >result.raw 2>&1
    fi
}

output=0

echo -en "\033[33;1m"

for test in "$@"
do
    if [ -x "${test}" ]
    then
        echo -e "\033[33;1mMEMTEST: ${test}"
        if do_test "${test}"
        then
            echo -e "\033[32;1mPASED memtest ${test}\033[0m"
        else
            echo -e "\033[31;1mFAILED memtest ${test}\033[0m"
            output=1
        fi
        cat result.raw | sed -n -e "s/==[^=]*== //" -e "/MEMTEST:/p;/LEAK SUMMARY/,/ERROR SUMMARY/p"
        rm -f result.raw
    fi
done

echo -en "\033[0m"


exit ${output}

#/bin/bash

output=0

for test in "$@"
do
    echo -e "\033[33mTesting: ${test}\033[0m"
    if [ -x "${test}" ] && "${test}"
    then
        echo -e "\033[32;1mSUCCESS: ${test}\033[0m"
    else
        echo -e "\033[31;1mFAILED memtest ${test}\033[0m"
        output=1
    fi
done

echo -e "\033[0m"

exit ${output}

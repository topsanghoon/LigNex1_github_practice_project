#!/bin/bash

# 현재 폴더명(예: Yoon) 추출
USER_DIR=$(basename "$(pwd)")
SRC_FILE="4101.cpp"
EXE_FILE="4101.out"

echo "🔨 Compiling $SRC_FILE from $USER_DIR ..."

# 컴파일
g++ -std=c++17 -O2 -o "$EXE_FILE" "$SRC_FILE"
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi
echo "✅ Compilation succeeded!"

echo "🚀 Running tests..."

# 테스트 입력/출력 정의
inputs=(
"1 19
4 4
23 14
0 0"
"10 20
20 10
0 0"
"100 99
99 100
0 0"
"5 5
0 0"
"1 2
2 3
0 0"
)

expected=(
"No
No
Yes"
"No
Yes"
"Yes
No"
"No"
"No
No"
)

total=${#inputs[@]}
pass=0

# 테스트 실행
for ((i=0; i<total; i++)); do
    echo -n "Test $((i+1))/$total ... "

    output=$(echo "${inputs[$i]}" | ./$EXE_FILE)

    # 문자열 직접 비교
    if [[ "$output" == "${expected[$i]}" ]]; then
        echo "✅ PASS"
        ((pass++))
    else
        echo "❌ FAIL"
        echo "   Expected:"
        echo "${expected[$i]}"
        echo
        echo "   Got:"
        echo "$output"
        echo
    fi
done

echo "==========================="
echo "🎯 Result: $pass / $total tests passed."


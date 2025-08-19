#!/bin/bash

# 현재 디렉토리명 추출 (예: Collaboration)
USER_DIR=$(basename "$(pwd)")
SRC_FILE="morse.cpp"
EXE_FILE="morse.out"
OUTPUT_FILE="output.txt"

echo "🔨 Compiling $SRC_FILE from $USER_DIR ..."

# 컴파일
g++ -std=c++17 -O2 -o "$EXE_FILE" "$SRC_FILE"
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi
echo "✅ Compilation succeeded!"

echo "🚀 Running Morse code tests..."

# 테스트 입력 (단일 줄 + 다중 줄)
inputs=(
"HELLO
END"
"SOS
END"
"123
END"
"HELLO WORLD
END"
"OpenAI
END"
"HELLO
WORLD
AI
END"
"SOS
123
HELLO
END"
)

# 기대 출력 (output.txt 기준)
expected=(
".... . .-.. .-.. ---
HELLO"
"... --- ...
SOS"
".---- ..--- ...--
123"
".... . .-.. .-.. --- / .-- --- .-. .-.. -..
HELLO WORLD"
"--- .--. . -. .- ..
OPENAI"
".... . .-.. .-.. ---
HELLO
.-- --- .-. .-.. -..
WORLD
.- ..
AI"
"... --- ...
SOS
.---- ..--- ...--
123
.... . .-.. .-.. ---
HELLO"
)

total=${#inputs[@]}
pass=0

# 테스트 실행
for ((i=0; i<total; i++)); do
    echo -n "Test $((i+1))/$total ... "

    # 프로그램 실행 → output.txt 생성 (덮어쓰기)
    echo "${inputs[$i]}" | ./$EXE_FILE > /dev/null

    # output.txt 읽기
    if [ ! -f "$OUTPUT_FILE" ]; then
        echo "❌ FAIL (output.txt not found)"
        continue
    fi

    output=$(cat "$OUTPUT_FILE")

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


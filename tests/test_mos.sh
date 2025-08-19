#!/bin/bash

SRC_FILE="src/morse.cpp"
EXE_FILE="src/morse.out"
OUTPUT_FILE="src/output.txt"

echo "🔨 Compiling $SRC_FILE ..."
g++ -std=c++17 -O2 -o "$EXE_FILE" "$SRC_FILE"
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    exit 1
fi
echo "✅ Compilation succeeded!"

echo "🚀 Running Morse code tests..."

# 테스트 입력
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

# 기대 출력
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

    # 프로그램 실행 → output.txt 생성 (현재 폴더에)
    echo "${inputs[$i]}" | "$EXE_FILE" > /dev/null

    # output.txt 가 src에 있도록 강제로 이동
    mv -f output.txt "$OUTPUT_FILE" 2>/dev/null

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


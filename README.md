# C 협업 실습 프로젝트

이 저장소는 GitHub 협업 실습을 위한 예제 프로젝트입니다.  
C 언어를 기반으로 간단한 유틸 함수와 테스트 코드를 작성하면서 GitHub 협업 흐름(Branch → Commit → PR → Merge)을 경험합니다.

---

## 👥 팀
| 역할 | 이름 | GitHub |
|------|------|--------|
| 조장 | 윤상훈 | @topsanghoon1 |
| 팀원1 |  |  |

> Todo 1 : 각자 위치하고 싶은 자리에 자신의 이름을 넣어보세요.

---

## 📂 디렉토리 구조
repo/
├─ include/ # 헤더 파일(.h)
├─ src/ # 기본 함수 구현 + participants/ (팀원별 함수)
├─ tests/ # 테스트 코드
├─ scripts/ # 빌드/테스트 스크립트
└─ .github/ # PR 템플릿, Actions 워크플로우

---

## 🚀 빌드 & 실행
```bash
./scripts/build.sh
./scripts/test.sh
```

---

## 실습 과정

0. Git 사용은 VMware에서 사용중인 ubuntu를 사용하여 진행합니다.
1. 초기 디렉토리는 Private으로 만들어져 있습니다. 각자 SSH 키를 생성해서 등록하고, Git clone을 해보도록 합니다.
2. 두가지 실습 코드 작성을 실시합니다. 하나는 각자 수행하며, 나머지 하나는 같이 작성합니다. 이 과정에서 add, merge, pull_request, pull 그리고 conflict 해결 방법을 알아봅니다.
3. 코드 작성 후 실행하여 테스트를 해봅니다. 제대로 작성되었는지 확인해 봅니다.

---

## 실습 가이드

### 사용자 정보 설정

``` bash
git config --global user.name "<사용자 이름>"
git config --global user.email "<사용자 이메일>"

#아래 코드를 통해 제대로 설정되었는지 확인할 수 있습니다.
git config --list
```

---

### SSH 키 생성

``` bash
#새로운 ssh 토큰 키를 생성하는 과정.  (ed25519 는 공개키 생성 알고리즘)
#저장 위치 등을 묻는데 그냥 "Enter"를 눌러서 넘어가세요.
ssh-keygen -t ed25519 -C "topsanghoon1@gmail.com"

# ssh-agent 실행 및 키 등록
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519

# 공개키 확인 & github에 등록
cat ~/.ssh/id_ed25519.pub
# 나온 내용 전부를 복사하여 "github -> setting -> SSH and GPG keys -> SSH keys에 추가" 에 넣어 저장합니다.

#연결 테스트
ssh -T git@github.com
#"Hi <사용자이름>! You've successfully authenticated, but GitHub does not provide shell access." 가 나오면 성공

```

### git clone

``` bash
#깃허브에서 코드 말고 SSH로 경로를 복사하여 clone을 실시.
git clone <ssh 경로>
```


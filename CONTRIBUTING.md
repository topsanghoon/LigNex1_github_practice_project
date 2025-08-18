# 기여 가이드

이 프로젝트는 GitHub 협업 실습용입니다.  
다음 규칙에 따라 브랜치 생성, 커밋, PR을 진행해주세요.

---

## 🔀 브랜치 전략
- 기능 단위 브랜치: `feature/<이름>-<주제>`
  - 예: `feature/sanghoon-isprime`

---

## 💬 커밋 메시지 규칙
- 권장 Prefix: `feat:`, `fix:`, `docs:`, `test:`, `chore:`
- 예: `feat: add gcd function (Closes #3)`

---

## 📥 Pull Request
- main 브랜치로 PR 생성
- CI 통과 필수
- 리뷰어 관리자 포함 전원 승인

---

## ⚡ 충돌 해결
```bash
git fetch origin
git rebase origin/main
# <<<<<<<, =======, >>>>>>> 마커 해결
git add .
git rebase --continue
git push -f
```


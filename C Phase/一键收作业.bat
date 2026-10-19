@echo off
title B306 招新作业归档

rem ================= 用法 =================
rem  双击就能跑：扫最近 30 天，第 3 轮，严格口径
rem      （主题 + 文件名都要「学号-姓名-笔记/答案3」对得上）
rem  临时换轮次/范围：在本文件所在目录开 cmd，敲
rem      一键收作业.bat --rule 4
rem      一键收作业.bat --since 40 --rule 4
rem  先看看不下、不写任何文件：加 --dry-run
rem  想放宽（比如不卡文件名里的学号）：把下面那行 --strict 删掉
rem  每周换轮：把下面那个 3 改成 4、5、6……
rem  自己敲的 --rule 会覆盖默认值（后面的参数说了算），不会打起来
rem ========================================

set SCRIPT=C:\Users\WilliTourt\.openclaw\workspace\scripts\qq_mail_harvest.py

if not exist "%SCRIPT%" (
  echo [x] 找不到脚本：%SCRIPT%
  echo     看看 openclaw 工作区还在不在。
  pause
  exit /b 1
)

echo 开始收作业...（第一次跑慢，几分钟到几十分钟）
echo.
python "%SCRIPT%" --since 30 --rule 3 --strict %*

echo.
echo ====== 跑完了 ======
echo 归档目录：%USERPROFILE%\Desktop\B306招新\作业归档\
pause

printf "\n\nAuto Git-Hub Push Script Initiated !!\n\n"
cd ~/OneDrive/code/leetcode_grind/
git status
git add .
printf "\n\nAll changes added to commit queue...\n\n"
git commit -m "Daily Prac"
printf "\n\n Git Commit successful...\n\n"
git push
printf "\n\nGit push successfull...\n\n"
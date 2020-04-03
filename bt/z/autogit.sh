printf "\n\nAuto Git-Hub Push Script Initiated !!\n\n"
cd ~/OneDrive/code/leetcode_grind/
git status
git add .
printf "\nAll changes added to commit queue...\n"
git commit -m "Daily Prac"
printf "\n Git Commit successful...\n"
git push
printf "\nGit push successfull...\n"
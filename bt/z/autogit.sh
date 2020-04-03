printf "\n\nAuto Git-Hub Push Script Initiated !!\n\n"
cd ~/OneDrive/code/leetcode_grind/
git status
read
printf "\n\nAll changes added to commit queue...\n\n"
git commit -a -m "Daily Prac"
read
printf "\n\n Git Commit successful...\n\n"
git push
read
printf "\n\nGit push successfull...\n\n"
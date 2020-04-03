echo "Auto Git-Hub Push Script Initiated !!"
cd ~/OneDrive/code/leetcode_grind/
git status
git add .
echo "\nAll changes added to commit queue...\n"
git commit -m "Daily Prac"
echo "\n Git Commit successful...\n"
git push
echo "\nGit push successfull...\n"
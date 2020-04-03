echo "Auto Git-Hub Push Script Initiated !!"
cd ~/OneDrive/code/leetcode_grind/
git status
git add .
echo "All changes added to commit queue..."
date = %DATE%
git commit -m "Daily Prac $date"
echo "Git commit successful..."
git push
echo "Git push successfull..."
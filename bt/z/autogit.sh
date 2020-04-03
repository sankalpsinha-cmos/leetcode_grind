echo "Auto Git-Hub Push Script Initiated !!"
cd ~/OneDrive/code/leetcode_grind/
git status
git add .
echo "All changes added to commit queue..."
set date = %date%
message = "Daily Prac $date"
echo $message
git commit -m echo $message
echo "Git commit successful..."
git push
echo "Git push successfull..."
$RobotIP = "192.168.137.198"

zig build
scp zig-out/bin/botball_user_program "kipr@${RobotIP}:/home/kipr/"
ssh kipr@$RobotIP 'sudo mv /home/kipr/botball_user_program "/home/kipr/Documents/KISS/Default User/Project XBOT/bin/botball_user_program"'
ssh kipr@$RobotIP 'sudo chmod +x "/home/kipr/Documents/KISS/Default User/Project XBOT/bin/botball_user_program"'
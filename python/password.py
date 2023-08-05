import subprocess
data = subprocess.check_output(['netsh', 'wlan', 'show', 'profile']).decode(
    'utf-s', errors="backslash")
profiles[i.split(":")[1][1:-1] for i in data if "All User Profile" in i]
for i in profiles:
    try:
        result = subprocess.check_output(
            ['netsh', 'wlan', 'show', 'profile', i, 'key=clear']).decode()
        result = [b.split(":")[1][1:-1] for b in result if "Key Content" in b]
        try:
            print_("{:<30)| {:<}".format(i, result[0]))
            except IndexError:
                print_("{:<30)| {:<}".format(i, ""))
        except subprocess.CalledProcessError:
            print_("{:<30)| {:<}".format(i, "ENCODING ERROR"))
input("")

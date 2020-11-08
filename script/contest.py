import sys
import os

args = sys.argv

if not len(args) == 4:
    print("コンテスト名と問題数とURlを入力してください")
    sys.exit(0)

path = os.getcwd();
path = path + "/" + args[1]

template_path = "/home/sarashin/Documents/c++/AtCoder/template"

prob_num = int(args[2])
url = args[3]

if prob_num > 26:
    print("問題数は26以下でお願いします")
    sys.exit(0)

if not os.path.exists(path):
    os.mkdir(path)

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
lower_letters = letters.lower()

url_last = url.split("/")[-1]

with open(path+"/urls", 'w') as f:
    for i in range(prob_num):
        prob_url = url + "/tasks/"+ url_last + "_" + lower_letters[i:i+1]
        f.write(prob_url)
        if i != prob_num-1:
            f.write("\n")

templates = ""

with open(template_path) as f:
    templates = f.read()

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

print("Making file now ...")

for i in range(prob_num):
    prob_name = letters[i:i+1] + ".cpp"
    print(prob_name)
    prob_path = path+"/"+letters[i:i+1]
    os.mkdir(prob_path)
    prob_name = prob_path + "/" + prob_name
    with open(prob_name, 'w') as f:
        f.write(templates)

print("Prepare has just finished!! Good luck for your contest!!")
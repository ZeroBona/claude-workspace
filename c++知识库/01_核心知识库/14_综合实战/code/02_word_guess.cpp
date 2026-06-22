#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const vector<string> WORDS = {
    "computer", "program", "language", "science",
    "algorithm", "keyboard", "monitor", "software"
};

string chooseWord() {
    srand(time(0));
    return WORDS[rand() % WORDS.size()];
}

string initProgress(const string &word) {
    return string(word.length(), '_');
}

void showProgress(const string &progress, int wrongCount) {
    for (char c : progress) cout << c << " ";
    cout << "\n错误次数：" << wrongCount << endl;
}

bool isGuessRight(const string &word, char guess, string &progress) {
    bool found = false;
    for (size_t i = 0; i < word.length(); i++) {
        if (word[i] == guess) {
            progress[i] = guess;
            found = true;
        }
    }
    return found;
}

int main() {
    const int MAX_WRONG = 6;
    string word = chooseWord();
    string progress = initProgress(word);
    int wrongCount = 0;
    vector<char> guessedLetters;

    cout << "=== 猜单词游戏 ===" << endl;
    cout << "单词长度：" << word.length() << "，最多猜错" << MAX_WRONG << "次" << endl;

    while (wrongCount < MAX_WRONG && progress != word) {
        cout << "\n当前进度：";
        showProgress(progress, wrongCount);

        char guess;
        cout << "猜一个字母：";
        cin >> guess;

        bool alreadyGuessed = false;
        for (char c : guessedLetters) {
            if (c == guess) {
                alreadyGuessed = true;
                break;
            }
        }

        if (alreadyGuessed) {
            cout << "这个字母已经猜过了！" << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (isGuessRight(word, guess, progress)) {
            cout << "✅ 猜对了！" << endl;
        } else {
            cout << "❌ 猜错了！" << endl;
            wrongCount++;
        }
    }

    cout << "\n=== 游戏结束 ===" << endl;
    if (progress == word) {
        cout << "🎉 恭喜你猜对了！单词是：" << word << endl;
    } else {
        cout << "😅 游戏结束，正确答案是：" << word << endl;
    }

    return 0;
}

# Homework Programming 1st year
---
## Text Highlight

Even though writing code might sometimes seem like an easy task, it involves a lot of theoretical knowledge and a great deal of practice, especially when dealing with complex programs. Therefore, to assist users, text highlighting has been created, which means keywords such as "for", "while", "int", "float" will be emphasized for easier understanding of the code. In this problem, we aim to simulate the TextHighlight feature.

To simulate text highlighting, we will "underline" encountered keywords on the next line. Each character of the keyword will be underlined using the `_` character (including spaces for multi-word keywords), and for other characters that are not part of the keywords, we will use a space ` `.

**Note:** Since many programs allow writing key sequences formed by multiple words with a variable number of spaces between them, this case will also be considered. However, avoid writing code in this manner as it becomes hard to understand and violates coding style guidelines.

For this task, we consider the following words and two-word sequences as keywords: `first of`, `for`, `for each`, `from`, `in`, `is`, `is a`, `list of`, `unit`, `or`, `while`, `int`, `float`, `double`, `string`.

---

## Autocomplete

Autocomplete is a widely used functionality. Although it theoretically helps save time, it can also lead to errors depending on how it is used. Over time, many issues have been resolved, and autocomplete is useful in almost every case. One of the most useful and used forms is Google search autocomplete. However, this autocomplete is quite complex, using not only the current user's previous searches but also those of other users, keywords from existing Google pages, and the most popular searches.

Therefore, in this problem, we aim to implement an autocomplete starting from a certain number of words (a mini-dictionary) and updating it with the introduction of new words or the use of recent ones. Each word in the dictionary will initially have a priority of 0 and will be represented as follows:

```c
struct dictionary_entry {
    char* word;
    int priority;
};
```

Each word typed by the user can fall into one of the following 3 categories:

- **word** - there is no match in the dictionary, so it will be output exactly as entered and added with a priority of 1 to the dictionary, as it is its first appearance in the text.

- **word\*** - it matches a word in the dictionary that has a higher priority, but the user prefers to use their own form, despite its lower priority (the word may or may not exist in the dictionary, in which case it will be added). The word will be displayed, and its priority will be increased.

- **word** - it matches one or more words in the dictionary (starting with the word), and the one with the highest priority will be selected. Additionally, the priority of the selected word from the dictionary will increase.

**Note:** If there are words in the dictionary with the same priority and a match is sought for a given word, the word considered closest in lexicographical order will be selected. For example, if searching for a match for "abc" and the dictionary has "abcde" with priority 2 and "abce" also with priority 2, "abcde" will be selected because it is smaller than "abce".

---

## Bitwise Calculator

The third functionality implemented is a bitwise calculator supporting operations on 4-bit numbers. It is straightforward and supports up to 4 consecutive operations.

Numbers and operations are extracted from an unsigned int entered via the keyboard, with the following format:

- Numbers are represented in 4 bits.
- Operations are represented in 2 bits, encoded as follows:

| Operation         | Encoding |
| ----------------- | -------- |
| Addition          | 00       |
| Swap              | 01       |
| Left Rotation     | 10       |
| XOR               | 11       |

### Addition

The result of this operation will be the sum of the two numbers represented in 4 bits. For example, after applying the addition operation to `0001` and `0101`, the result will be `0110`.

### Swap

In this operation, the bit at position p1 is swapped with the bit at position p2 for the first number. Here, p1 represents the first 2 bits from the second number, and p2 represents the last 2 bits from the second number. For example, applying the swap operation to `0001` and `1100` results in `1000`. The bit at position 11 (3, the last bit of the first number) will be swapped with the bit at position 00 (0, the first bit of the first number).

### Left Rotation

Applying this operation to two numbers, nr1 and nr2, results in nr1 being rotated left by nr2 times. For example, applying the rotation operation to `1011` and `0101` (5) results in `0111`.

### XOR

The result of this operation will be the XOR of the two 4-bit numbers. For example, after applying the XOR operation to `1011` and `0101`, the result will be `1110`.

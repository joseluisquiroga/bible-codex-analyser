# bible-codex-analyser

This project contains

A database with the following tables:

## BIBLE_IN_STRONG_VERSES.table

Each line contains a bible codex verse in the following format:

BOOK_ID | CHAPTER_ID | VERSE_ID | VERSE_IN_STRONG_CODES

- The VERSE_IN_STRONG_CODES is a concatenation of Strong Codes using ':' as the concatenation character.
- The verses of the old testament are taken directly from the hebrew codex
- The verses from the new testament are taken directly from the greek codex
- All the information comes from BIBLE_IN_STRONG_WORDS.table

It is the bible codex written in hebrew and greek but using only Strong Codes.

## BIBLE_IN_STRONG_WORDS.table

Inspired by biblehub.com/text verse analysis format, each line contains a single bible codex word instance in the following format:

BOOK_ID | CHAPTER_ID | VERSE_ID | WORD_ID | WORD_STRONG_CODE_ID | WORD_PHONEM_CODE | ORIGINAL_TEXT | TRANSLITERATED_TEXT | ENGLISH_TEXT

- ORIGINAL_TEXT is in hebrew for the old testament and greek for the new testament.
- All hebrew is WITHOUT nikuda because ancient hebrew did not use nikuda.
- All greek is WITHOUT capitals or puntuacted characters because koine greek did not use them.
- All transliteration is done with the tables in doc/TRANSLITERATION_MAPS.txt generating a one to one function between the original text and the transliterated text.

## BOOKS.table

Each lines identifies a book of the bible usign the following format:

BOOK_ID | BOOK_NAME

## MUTUAL_HEBREW_GREEK_TRANSLATIONS.table

Each line is a posible translation from greek to hebrew or from hebrew to greek using the following format:

STRONG_CODE_ID | NUM_TRANSLATION | TRANSLATION_STRONG_CODE_ID

- If the STRONG_CODE_ID is a G_CODE (a greek strong code) the TRANSLATION_STRONG_CODE_ID is a H_CODE (a posible hebrew strong code translation of STRONG_CODE_ID).
- If the STRONG_CODE_ID is a H_CODE (a hebrew strong code) the TRANSLATION_STRONG_CODE_ID is a G_CODE (a posible greek strong code translation of STRONG_CODE_ID).

## ROOTS.table

Each line contains a root of an Strong Code using the following format:

STRONG_CODE_ID | NUM_ROOT | ROOT_STRONG_CODE_ID

- ROOT_STRONG_CODE_ID is the number NUM_ROOT root of STRONG_CODE_ID.
- They are both either hebrew or both greek Strong Codes since the second is the root of the first.

## SEPTUAGINT.table

Inspired by biblehub.com/text verse analysis format, each line contains a Septuagint codex word instance in the following format:

BOOK_ID | CHAPTER_ID | VERSE_ID | WORD_ID | WORD_STRONG_CODE_ID | ORIGINAL_TEXT | WORD_GRAMMA

- ORIGINAL_TEXT is in greek since the Septuagint is the first greek translation of the old testament.
- All greek is WITHOUT capitals or puntuacted characters because koine greek did not use them.

## STRONG_CODE_DEFS.table

Each line contains an Strong Code definition using the following format:

STRONG_CODE_ID | ORIGINAL_TEXT | GRAMMA | TRANSLITERATION | ENGLISH_TEXT

- ORIGINAL_TEXT is in hebrew for the old testament and greek for the new testament.
- All hebrew is WITHOUT nikuda because ancient hebrew did not use nikuda.
- All greek is WITHOUT capitals or puntuacted characters because koine greek did not use them.
- All transliteration is done with the tables in doc/TRANSLITERATION_MAPS.txt generating a one to one function between the original text and the transliterated text.

## VERSE_REFERENCES.table

Each line contains a bible verse reference using the following format:

BOOK_ID | CHAPTER_ID | VERSE_ID | REF_NUM | REF_BOOK_ID | REF_CHAPTER_ID | REF_VERSE_ID

The verse identified by (BOOK_ID | CHAPTER_ID | VERSE_ID) has a reference to the verse identified by (REF_BOOK_ID | REF_CHAPTER_ID | REF_VERSE_ID) and REF_NUM is the a consecutive of all the references that a particular verse has.

# SQLite

This set of tables can be imported to SQLite to process information with the SQL language.

# Linux tools

The bash script files

1. print_all_NT_codex_verses_with_death_sh
2. print_all_NT_codex_verses_with_eternal_and_death_sh
3. print_all_NT_codex_verses_with_eternal_life_sentence_sh

Show how the file BIBLE_IN_STRONG_VERSES.table can be used togheter with grep and the c++ program print_verses (that should be build with make and added to the path) to extract all the verses in the original codex that had the desired Strong Codes.

Steps done by those examples:

1. Select a set of words that you would like to find in the codex.
2. Find the Strong Codes for those words
3. Search the verses that contain those Strong Codes in BIBLE_IN_STRONG_VERSES.table
4. Write the those verses in your prefered language.

**This simple technique allows to study the bible in its FIRST written languages, hebrew and greek, as it was written, and NOT as it was translated.**






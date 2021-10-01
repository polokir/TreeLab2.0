#pragma once
#include "BinTree.h"

#include <iostream>

const char FILE_NAME[] = "tree.bin";

struct FileWorker
{
	FILE* file;

	FileWorker();
	~FileWorker();

	void insert(const BinTree&);
	void print();
	//void sort(const int);
	int getFileSize(FILE* file);
	//void renameFiles(FILE* file1, FILE* file2, const char NAME_1[], const char NAME_2[]);
};

FileWorker::FileWorker() {
	fopen_s(&file, FILE_NAME, "ab+");
}

FileWorker::~FileWorker() {
	fclose(file);
}

void FileWorker::insert(const BinTree& tree) {
	fseek(file, 0, SEEK_END);
	fwrite(&tree, sizeof(tree), 1, file);
}

void FileWorker::print() {
	BinTree tree(0, 0, 0, 0);
	int size = getFileSize(file);
	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < size; ++i) {
		fread(&tree, sizeof(BinTree), 1, file);
		tree.output();
	}
}

int FileWorker::getFileSize(FILE* file) {
	if (file == nullptr)
		return -1;
	fseek(file, 0, SEEK_END);
	return ftell(file) / sizeof(BinTree);
}
#pragma once

void SaveFile(std::string text, int count, std::string digits);
std::string CheckFileName(std::string filePath);
bool ValidateName(std::string filePath);
int UploadFromFile(std::string fileName);
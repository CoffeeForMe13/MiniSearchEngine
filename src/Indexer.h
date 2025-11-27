#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Indexer
{
public:
	using InvertedIndex = std::unordered_map<std::string, std::vector<std::string>>;

	void addDocument(const std::string& filePath, const std::string& content);
	const InvertedIndex& getIndex() const;

private:
	InvertedIndex index_;

	std::vector<std::string> tokenize(const std::string& text) const;
	std::string normalize(const std::string& word) const;

};
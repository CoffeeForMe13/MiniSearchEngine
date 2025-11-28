#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Indexer
{
public:
	using InvertedIndex = std::unordered_map<std::string, std::vector<std::string>>;
	using PositionalIndex = std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int>>>;

	void addDocument(const std::string& filePath, const std::string& content);
	const InvertedIndex& getIndex() const;
	const PositionalIndex& getPositionalIndex() const;

private:
	InvertedIndex index_;
	PositionalIndex positionalIndex_;

	std::vector<std::string> tokenize(const std::string& text) const;

};

// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_GMSURVEYANSWERS_REC_HPP
#define DB_GMSURVEYANSWERS_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct GMSurveyAnswersRec {
	static constexpr uint32_t columnCount = 20;
	static constexpr uint32_t rowSize = 80;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_Sort_Index;
	int32_t m_GMSurveyQuestionID;
	const char* m_Answer_lang;

	static const char* GetFilename() {
		return "DBFilesClient\\GMSurveyAnswers.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t Answer_langOfs[16];
		uint32_t Answer_langMask;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sort_Index, sizeof(this->m_Sort_Index), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GMSurveyQuestionID, sizeof(this->m_GMSurveyQuestionID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Answer_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_Answer_lang = &stringBuffer[Answer_langOfs[CURRENT_LANGUAGE]];
		} else {
			this->m_Answer_lang = "";
		}

		return true;
	}
};

#endif
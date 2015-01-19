#ifndef CENTRALITY_JSON_WRITER_H
#define CENTRALITY_JSON_WRITER_H

#include <iostream>
#include <fstream>
#include "temporal_list_digraph_for_centrality.h"

using namespace std;

class CentralityJsonWriter {
public:
	CentralityJsonWriter(char* filePath, TemporalListDigraphForCentrality &temporal_cg) : cg(temporal_cg){
		outputFile.open (filePath,ios::out);
	}

	void writeHeader(int topK, vector<string> measureSet) {
		stringstream ss;
		ss << topK;

		outputFile << "{\n"+writeIndent(1)+"\"centrality_test\": {" << endl;
		outputFile << writeIndent(2) + "\"topK\": " + ss.str() + "," << endl;
		outputFile << writeIndent(2) + "\"measures\": [\n" + writeMeasureSet(measureSet) + writeIndent(2) + "]," << endl;

	}

	void writeInterval() {
		//TODO: write functionality
	}

	void close() {
		//TODO: finish json and close file
		outputFile << writeIndent(1)+"}\n}" << endl;
		outputFile.close();
	}

	string writeIndent(int times) {
		string output = "";
		for(int i=0; i<times; ++i) {
			output += indent;
		}
		return output;
	}

	string writeMeasureSet(vector<string> measureSet) {
		string output ="";
		for (int i=0; i<measureSet.size(); ++i) {
			output += writeIndent(3) + "\"" + measureSet[i] + "\"";
			if(i<measureSet.size()-1) {
				output += ",";
			}
			output += "\n";
		}
		return output;
	}

private:
	ofstream outputFile;
	TemporalListDigraphForCentrality &cg;
	string indent = "  ";

};

#endif

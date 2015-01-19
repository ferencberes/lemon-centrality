#ifndef CENTRALITY_UTILS_H
#define CENTRALITY_UTILS_H

#include <lemon/list_graph.h>
using namespace lemon;

typedef unsigned long int NodeId;

struct IdValuePair {
	NodeId id;
	float value;

	IdValuePair(NodeId k, float v) :
			id(k), value(v) {
	}

	void str() {
		std::cout << "id: " << id << ", score: " << value << std::endl;
	}

};

struct pair_comparator {
	inline bool operator()(const IdValuePair& struct1,
			const IdValuePair& struct2) {
		return (struct1.value > struct2.value);
	}
};

struct TopKSelector {
	unsigned int k_max_size;
	std::vector<IdValuePair> vec;

	TopKSelector(int k) :
			k_max_size(k) {
	}

	void push(IdValuePair newValue) {
		if (vec.size() >= k_max_size) {
			if (vec.back().value < newValue.value) {
				vec.pop_back();
				vec.push_back(newValue);
				sort();
			}
		} else {
			vec.push_back(newValue);
		}
	}

	void sort() {
		std::sort(vec.begin(), vec.end(), pair_comparator());
	}
};

struct salsa_data {
	float authority;
	float hub;

	salsa_data() {
		authority = 1.0;
		hub = 0.0;
	}

	void setAuthorityValue(float value) {
		authority = value;
	}

	void setHubValue(float value) {
		hub = value;
	}
};

typedef ListDigraph::NodeMap<NodeId> IdentifierMap;
typedef ListDigraph::NodeMap<long> NeighbourMap;
typedef ListDigraph::NodeMap<float> CentralityMeasureMap;
typedef ListDigraph::NodeMap<salsa_data> SalsaMeasureMap;

#endif

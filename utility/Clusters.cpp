/* 
    pMMF is an open source software library for efficiently computing
    the MMF factorization of large matrices.

    Copyright (C) 2015 Risi Kondor, Nedelina Teneva, Pramod Mudrakarta
    
    This file is part of pMMF.

    pMMF is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "Clusters.hpp"

template<>
string Clusters<BlockIndexPair>::str() const {
	ostringstream sstream;
	for (int i = 0; i < vector<vector<BlockIndexPair>*>::size(); i++) {
		sstream << "Cluster " << i << ":" << endl;
		auto* ptr = vector<vector<BlockIndexPair>*>::operator[](i);
		if (ptr == nullptr)
			continue;
		for (auto& p : *ptr)
			sstream << "(" << p.block << "," << p.index << ")";
		sstream << endl;
	}
	return sstream.str();
}

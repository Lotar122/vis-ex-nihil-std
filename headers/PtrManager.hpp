#pragma once
#include <typeindex>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <any>

namespace nihil::nstd {
	using PtrManagerDeleteFunction = void (*)(void*);

	class PtrManagerClass 
	{
	public:
		std::unordered_map<std::type_index, PtrManagerDeleteFunction> deleteFunctions;
		std::unordered_set<std::pair<std::type_index, void*>> pointers;

		void registerType(std::type_index type_id, PtrManagerDeleteFunction function)
		{
			deleteFunctions.insert(std::make_pair(type_id, function));
		}

		void addPointer(std::type_index type_id, void* ptr)
		{
			pointers.insert(std::make_pair(type_id, ptr));
		}

		~PtrManagerClass()
		{
			for (auto& x : pointers)
			{
				auto y = deleteFunctions.find(x.first);

				y->second(x.second);
			}
		}
	};

	PtrManagerClass PtrManager;
}
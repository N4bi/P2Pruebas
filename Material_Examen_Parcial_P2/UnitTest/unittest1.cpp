#include "stdafx.h"
#include "CppUnitTest.h"
#include "../p2DynArray.h"
#include "../p2Point.h"
#include "../p2SString.h"
#include "../p2List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// DYN ARRAY -----------------------------------------
		TEST_METHOD(DynArray_ctor)
		{
			p2DynArray<int> array;
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			p2DynArray<int> array(33);
			Assert::AreEqual((int)array.GetCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			p2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			p2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			int a, b;

			Assert::IsTrue(array.Pop(a));
			Assert::IsTrue(array.Pop(b));

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 1);
			Assert::AreEqual(a, 3);
			Assert::AreEqual(b, 2);
		}

		TEST_METHOD(DynArray_clear)
		{
			p2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			array.Clear();

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			p2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_at)
		{
			p2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(*(array.At(0)), 1);
			Assert::AreEqual(*(array.At(1)), 2);
			Assert::AreEqual(*(array.At(2)), 3);
			Assert::IsNull(array.At(3));
		}

		TEST_METHOD(DynArray_resize)
		{
			p2DynArray<int> array;

			for(int i = 0; i < 999; ++i)
			{
				array.PushBack(i);
			}

			Assert::AreEqual(*(array.At(900)), 900);
			Assert::IsNull(array.At(1000));

			Assert::AreEqual((int)array.GetCapacity(), 1008);
			Assert::AreEqual((int)array.Count(), 999);
		}

		TEST_METHOD(DynArray_insert)
		{
			p2DynArray<int> array;

			for(int i = 0; i < DYN_ARRAY_BLOCK_SIZE; ++i)
			{
				array.PushBack(i);
			}

			array.Insert(999, 3);
			array.Insert(888, 17);
			array.Insert(777, 50);

			Assert::IsFalse(array.Insert(777, 50));
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE * 2);
			Assert::AreEqual((int)array.Count(), 18);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[17], 888);
		}

		// p2SString -----------------------------------------
		TEST_METHOD(SString_empty_ctor)
		{
			p2SString s;
			Assert::AreEqual((int)s.Length(), 0);
		}
		TEST_METHOD(SString_char_ctor)
		{
			p2SString s("Hola mundo");
			Assert::AreEqual((int)s.Length(), 10);
		}
		TEST_METHOD(SString_format_ctor)
		{
			p2SString s("%s %s %d", "hola", "mundo", 12);
			Assert::AreEqual((int)s.Length(), 13);
		}
		TEST_METHOD(SString_copy_ctor)
		{
			p2SString s("%s %s %d", "hola", "mundo", 12);
			p2SString s2(s);
			Assert::AreEqual((int)s2.Length(), 13);
		}
		TEST_METHOD(SString_op_equal)
		{
			p2SString s1("Hola mundo");
			p2SString s2("Hola mundo");
			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(SString_op_notequal)
		{
			p2SString s1("Hola mundo 1");
			p2SString s2("Hola mundo 2");
			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(SString_op_equal_cstr)
		{
			p2SString s1("Hola mundo");
			Assert::IsTrue(s1 == "Hola mundo");
		}
		TEST_METHOD(SString_op_notequal_cstr)
		{
			p2SString s1("Hola mundo 1");
			Assert::IsTrue(s1 != "test");
		}
		TEST_METHOD(SString_op_assign)
		{
			p2SString s1("Hola mundo");
			p2SString s2;
			s2 = s1;
			Assert::IsTrue(s2 == "Hola mundo");
		}
		TEST_METHOD(SString_op_assign_cstr)
		{
			p2SString s1("Hola mundo");
			s1 = "this is a test";
			Assert::IsTrue(s1 == "this is a test");
		}
		TEST_METHOD(SString_op_concat)
		{
			p2SString s1("Hola mundo");
			p2SString s2("this is a test");
			s1 += s2;
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_op_concat_cstr)
		{
			p2SString s1("Hola mundo");
			s1 += "this is a test";
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_length)
		{
			p2SString s1("Hola mundo");
			Assert::AreEqual((int)s1.Length(), 10);
		}
		TEST_METHOD(SString_capacity)
		{
			p2SString s1("Hola mundo");
			Assert::AreEqual((int)s1.GetCapacity(), 11);
		}
		TEST_METHOD(SString_getstr)
		{
			p2SString s1("Hola mundo");
			Assert::AreEqual((int)strcmp("Hola mundo", s1.GetString()), 0);
		}
		TEST_METHOD(SString_clear)
		{
			p2SString s1("Hola mundo");
			s1.Clear();
			Assert::AreEqual((int)s1.Length(), 0);
		}

		// p2List --------------------------------------------
		TEST_METHOD(ListAdd)
		{
			p2List<int> mylist;
			Assert::AreEqual((int)mylist.add(5), 1);
		}

		TEST_METHOD(ListDel)
		{
			p2List<int> mylist;
			mylist.add(5);
			Assert::IsTrue(mylist.del(mylist.start));
			Assert::AreEqual((int)mylist.count(), 0);
		}

		TEST_METHOD(ListClear)
		{
			p2List<int> mylist;
			mylist.add(1); mylist.add(2); mylist.add(3);
			mylist.clear();
			Assert::AreEqual((int)mylist.count(), 0);
		}
	};
}
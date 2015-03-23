#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Programacion2Clases/P2DynArray.h"
#include"../Programacion2Clases/P2List.h"
#include"../Programacion2Clases/P2String.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		

		// DYN ARRAY -----------------------------------------
		TEST_METHOD(DynArray_ctor)
		{
			P2DynArray<int> array;
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			P2DynArray<int> array(33);
			Assert::AreEqual((int)array.GetCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			P2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			P2DynArray<int> array;

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
			P2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			array.Clear();

			Assert::AreEqual((int)array.GetCapacity(), DYN_ARRAY_BLOCK_SIZE);
			Assert::AreEqual((int)array.Count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			P2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		/*TEST_METHOD(DynArray_at)
		{
			P2DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(*(array.At(0)), 1);
			Assert::AreEqual(*(array.At(1)), 2);
			Assert::AreEqual(*(array.At(2)), 3);
			Assert::IsNull(array.At(3));
		}*/

		/*TEST_METHOD(DynArray_resize)
		{
			P2DynArray<int> array;

			for (int i = 0; i < 999; ++i)
			{
				array.PushBack(i);
			}

			Assert::AreEqual(*(array.At(900)), 900);
			Assert::IsNull(array.At(1000));

			Assert::AreEqual((int)array.GetCapacity(), 1008);
			Assert::AreEqual((int)array.Count(), 999);
		}*/

		TEST_METHOD(DynArray_insert)
		{
			P2DynArray<int> array;

			for (int i = 0; i < DYN_ARRAY_BLOCK_SIZE; ++i)
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

		// P2String -----------------------------------------
		TEST_METHOD(SString_empty_ctor)
		{
			P2String s;
			Assert::AreEqual((int)s.Length(), 0);
		}
		TEST_METHOD(SString_char_ctor)
		{
			P2String s("Hola mundo");
			Assert::AreEqual((int)s.Length(), 10);
		}
		TEST_METHOD(SString_format_ctor)
		{
			P2String s("%s %s %d", "hola", "mundo", 12);
			Assert::AreEqual((int)s.Length(), 13);
		}
		TEST_METHOD(SString_copy_ctor)
		{
			P2String s("%s %s %d", "hola", "mundo", 12);
			P2String s2(s);
			Assert::AreEqual((int)s2.Length(), 13);
		}
		TEST_METHOD(SString_op_equal)
		{
			P2String s1("Hola mundo");
			P2String s2("Hola mundo");
			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(SString_op_notequal)
		{
			P2String s1("Hola mundo 1");
			P2String s2("Hola mundo 2");
			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(SString_op_equal_cstr)
		{
			P2String s1("Hola mundo");
			Assert::IsTrue(s1 == "Hola mundo");
		}
		TEST_METHOD(SString_op_notequal_cstr)
		{
			P2String s1("Hola mundo 1");
			Assert::IsTrue(s1 != "test");
		}
		TEST_METHOD(SString_op_assign)
		{
			P2String s1("Hola mundo");
			P2String s2;
			s2 = s1;
			Assert::IsTrue(s2 == "Hola mundo");
		}
		TEST_METHOD(SString_op_assign_cstr)
		{
			P2String s1("Hola mundo");
			s1 = "this is a test";
			Assert::IsTrue(s1 == "this is a test");
		}
		TEST_METHOD(SString_op_concat)
		{
			P2String s1("Hola mundo");
			P2String s2("this is a test");
			s1 += s2;
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_op_concat_cstr)
		{
			P2String s1("Hola mundo");
			s1 += "this is a test";
			Assert::IsTrue(s1 == "Hola mundothis is a test");
		}
		TEST_METHOD(SString_length)
		{
			P2String s1("Hola mundo");
			Assert::AreEqual((int)s1.Length(), 10);
		}
		TEST_METHOD(SString_capacity)
		{
			P2String s1("Hola mundo");
			Assert::AreEqual((int)s1.GetSize(), 11);
		}
		TEST_METHOD(SString_getstr)
		{
			P2String s1("Hola mundo");
			Assert::AreEqual((int)strcmp("Hola mundo", s1.GetString()), 0);
		}
		TEST_METHOD(SString_clear)
		{
			P2String s1("Hola mundo");
			s1.Clear();
			Assert::AreEqual((int)s1.Length(), 0);
		}

		// P2List --------------------------------------------
		TEST_METHOD(ListAdd)
		{
			P2List<int> mylist;
			Assert::AreEqual((int)mylist.add(5), 1);
		}

		TEST_METHOD(ListDel)
		{
			P2List<int> mylist;
			mylist.add(5);
			Assert::IsTrue(mylist.del(mylist.start));
			Assert::AreEqual((int)mylist.countSize(), 0);
		}

		TEST_METHOD(ListClear)
		{
			P2List<int> mylist;
			mylist.add(1); mylist.add(2); mylist.add(3);
			mylist.Clear();
			Assert::AreEqual((int)mylist.countSize(), 0);
		}

	};
}
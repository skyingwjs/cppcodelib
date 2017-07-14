/**
  * @file    Test.cpp
  * @brief   这是一个DOXYGEN生成注释api文档的测试文件.
  * @author  wangjinshan
  * @date    2016/05/01 
  * @note    无
  * @version 1.0
  */ 

/** @brief  全局函数  */
void global_test();

/**
  * @class <Test>
  * @brief  这是一个测试类
  *
  * @note   mattersneeding attention
 */ 
class Test
{
public:
	/** @brief A enum, with inline docs */
	enum TEnum {
		TVal1, /**< enum value TVal1. */
		TVal2, /**< enum value TVal2. */
		TVal3 /**< enum value TVal3. */
	}

	*enumPtr, ///< enum pointer.
	enumVar; ///< enum variable.

	/** @brief 构造函数. */
	Test();

	/** @brief 析构函数. */
	~Test();

	/** @brief a normal member taking two arguments and returning an integer value. */
	int testMe(int a,const char *s);

	/**
	  *  @brief      testMeToo方法.
	  *  @param[in]  inArgName input argument description.type name:purpose(Range)
	  *  @Return:    void
	  *  @note       无
	  *  @date       2016.05.01
	  *  @see        other functions   
	  */
	virtual void testMeToo(char c1,char c2) = 0;
	int publicVar;///< a public variable.

	/** @brief a function variable, note Details. */
	int (*handler)(int a,int b);

	/** @brief brief before delaration */
	int m_func(int a);
};

/** A more elaborate description of the constructor. */
Test::Test()
{
}

/** A more elaborate description of the destructor. */
Test::~Test()
{
}

/**
  *  @brief      Thisis a brief description.
  *  @param[in]  inArgName input argument description.type name:purpose(Range)
  *  @param[out] outArgName output argument description.
  *  @Return:    description of the return value
  *  @note       matters needing attention
  *  @date       2016.05.01
  *  @see        other functions   
  */
int Test::testMe(int a,const char *s)
{
	return 0;
}

/**
  *  @brief      Thisis a brief description.
  *  @param[in]  inArgName input argument description.type name:purpose(Range)
  *  @param[out] outArgName output argument description.
  *  @Return:    description of the return value
  *  @note       matters needing attention
  *  @date       2016.05.01
  *  @see        other functions   
  */
int Test::m_func(int a)
{
	return 0;
}
#include"a.h"
#include"billCal.h"
#include"tarrif.h"
#include"unity.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_add_customer(void) {
  char ab[20] = "ram";
  int id =12;
  add_custm(ab,123,12);
  TEST_ASSERT_EQUAL_INT(123,find_fin(id));
  }

void test_bill(){
  float x = cal_bill(1,0,0,1,123);
  TEST_ASSERT_EQUAL_FLOAT( 714.58, x );
  
}

void test_bill2(){
  float x = cal_bill(2,0,1,1,95);
  TEST_ASSERT_EQUAL_FLOAT( 549.5, x );
  
}

void test_delete_customer(void){
  int id =12;
  del_s(12);
  TEST_ASSERT_EQUAL_INT(0,find_fin(id));
}



int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
 
  RUN_TEST(test_add_customer);
  RUN_TEST(test_delete_customer);
  RUN_TEST(test_bill);
  RUN_TEST(test_bill2);
  /* Close the Unity Test Framework */
  return UNITY_END();
}
python3 test_gen.py | xargs ./rush > result
diff -u test_case_result result 
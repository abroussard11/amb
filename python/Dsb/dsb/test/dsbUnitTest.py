'''
Created on Oct 10, 2015

@author: Aaron
'''
import unittest

class SimpleTestCase(unittest.TestCase):
    def setUp(self):
        ''' initialize variables here '''
    
    def tearDown(self):
        ''' clean up variables here '''

class FirstTest(unittest.TestCase):


    def testLoadPanel(self):
        self.assertEqual(1, 1)
    
    def testDoSomethingElse(self):
        self.assertAlmostEqual(1, 2, None, "msg", 2)


if __name__ == "__main__":
    import sys;sys.argv = ['', 'FirstTest']
    unittest.main(verbosity=2)

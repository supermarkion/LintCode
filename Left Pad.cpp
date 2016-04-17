/*
    You know what, left pad is javascript package and referenced by React: 
		Github link [https://github.com/stevemao/left-pad]
		One day his author unpublished it, then a lot of javascript projects in the world broken.
		You can see from github it's only 11 lines.
		You job is to implement the left pad function. If you do not know what left pad does, see examples below and guess.

    Link: http://www.lintcode.com/en/problem/left-pad/

    Example: 
    	leftpad("foo", 5)
		>> "  foo"

		leftpad("foobar", 6)
		>> "foobar"

		leftpad("1", 2, "0")
		>> "01"

    Solution: None

    Source: None
*/

class StringUtils {
    
    /* In the JavaScript:
    
    function leftpad (str, len, ch) {
      str = String(str);
      var i = -1;
      if (!ch && ch !== 0) ch = ' ';
      len = len - str.length;
      while (++i < len) {
        str = ch + str;
      }
      return str;
    }
    */
    
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        int i = -1;
        if (!padChar && padChar != '0') {
            padChar = ' ';
        }
    
        size = size - originalStr.size();
        
        while (++i < size) {
            originalStr = padChar + originalStr;
        }
        return originalStr;
    }
};
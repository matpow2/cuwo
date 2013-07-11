class PrintUtility:
    
    @staticmethod
    def to_hex(somestring):
        hexline = "".join(('%02X ' % ord(c)) for c in somestring)
        return "\n".join(hexline[i:min(i+48, len(hexline))] for i in range(0, len(hexline), 48))
    
    @staticmethod
    def to_binary(somestring):
        return "".join(('%0X' % ord(c)) for c in somestring)
    
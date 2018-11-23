cdef extern from "windows.h":
    ctypedef unsigned int DWORD
    ctypedef unsigned int MMRESULT

    cdef MMRESULT _TIMERR_NOERROR "TIMERR_NOERROR"

    DWORD timeGetTime_ "timeGetTime"()
    MMRESULT timeBeginPeriod_ "timeBeginPeriod"(DWORD period)
    MMRESULT timeEndPeriod_ "timeEndPeriod"(DWORD period)

TIMERR_NOERROR = _TIMERR_NOERROR

def timeGetTime():
    return timeGetTime_()

def timeBeginPeriod(period):
    return timeBeginPeriod_(period)

def timeEndPeriod(period):
    return timeEndPeriod_(period)

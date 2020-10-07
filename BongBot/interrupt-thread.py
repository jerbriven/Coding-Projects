import thread
import time
import threading
close = None
e = threading.Event()

def main():
    thread.start_new_thread(wait_for_input, tuple())
    thread.start_new_thread(do_something, tuple())

def wait_for_input():
    # raw_input()
    print("here")
    time.sleep(2)
    pass
    #    e.set()
    

def do_something():
    T0 = time.clock()
    while (time.clock() - T0) < 60 and not e.isSet(): #as long as 60s haven't elapsed
                                                      #and the flag is not set
        print("Hello there")
        #time.sleep(5)
    thread.interrupt_main() # kill the raw_input thread

def infinite_loop():
    while True:
        time.sleep(0.1)
        try:
            print("starting try")
            thread.start_new_thread(main, tuple())
            while 1:
                time.sleep(0.1) 
        except KeyboardInterrupt:
            #print("Press 1 to continue: ")
            #if input() == 1:
            print("KeyboardInterrupt")
            #else:
                #close = 1
    return 1

infinite_loop()

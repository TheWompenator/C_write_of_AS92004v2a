DATA_FILE = "data.json"

function ASINJECT_init()
    AS_link_data(DATA_FILE)
    return 0
end

function ASINJECT_begin_quiz()
    AS_print("Welcome to the NZ Trivia Quiz.\n\nPlease enter your name: ")
    local name = AS_get_str_input()
    AS_print("Hello " .. name .. "! Please enter your age: ")
    local age = AS_get_int_input()
    AS_print("\nWelcome to the NZ Trivia Quiz, In this Quiz you will be prompted with a question and then 4 answers labled A, B, C, or D. Simply type in the letter corrosponding to the correct answer and press enter.\nYou get one point for every question you get right. Good luck!\n")

    if age <= 7 then
        return 0
    else
        return 1
    end
end

function ASINJECT_end_quiz()
    total_questions = tostring(AS_total_questions())
    correct_answers = tostring(AS_total_correct())
    AS_print("That's the end of the quiz! you got " .. correct_answers .. " out of " .. total_questions .. " questions right!")
    return 0
end